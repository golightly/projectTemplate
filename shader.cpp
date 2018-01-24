#include <GL/glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>
#include "shader.h"

const GLchar* getFragmentSource() {
	const GLchar* fragSource = R"glsl(
    #version 150 core
    in vec2 Texcoord;
    out vec4 outColor;
    uniform sampler2D texSampler;
    void main()
    {
        outColor = texture(texSampler, Texcoord);
    }
)glsl";
	return fragSource;
}

const GLchar* getVertexSource() {
	const GLchar* vertSource = R"glsl(
    #version 150 core
    in vec2 position;
    in vec2 texcoord;
    out vec2 Texcoord;
    void main()
    {
        Texcoord = texcoord;
        gl_Position = vec4(position, 0.0, 1.0);
    }
)glsl";
	return vertSource;
}

void setupShader(Shader &shader) {
	shader.vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader.vertexShader, 1, &shader.vertexSource, NULL);
	glCompileShader(shader.vertexShader);
	shader.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader.fragmentShader, 1, &shader.fragmentSource, NULL);
	glCompileShader(shader.fragmentShader);
	shader.shaderProgram = glCreateProgram();
	glAttachShader(shader.shaderProgram, shader.vertexShader);
	glAttachShader(shader.shaderProgram, shader.fragmentShader);
	glBindFragDataLocation(shader.shaderProgram, 0, "outColor");
	glLinkProgram(shader.shaderProgram);
	glUseProgram(shader.shaderProgram);
	shader.posAttrib = glGetAttribLocation(shader.shaderProgram, "position");
	glEnableVertexAttribArray(shader.posAttrib);
	glVertexAttribPointer(shader.posAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	shader.texAttrib = glGetAttribLocation(shader.shaderProgram, "texcoord");
	glEnableVertexAttribArray(shader.texAttrib);
	glVertexAttribPointer(shader.texAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
}