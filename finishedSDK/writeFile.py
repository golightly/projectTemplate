import sys
import subprocess
from PIL import Image
output = ""
path = sys.argv[1]
for a in range (len(path)):
	if path[a] != '.':
		output += path[a]
	else:
		output += ".art"
		break
file = Image.open(path)
w, h = file.size
pixels = file.convert("RGBA")
pixelArray = [[0 for y in range(h)] for x in range(w)]
for one in range(w):
	for two in range(h):
		r,g,b,a = pixels.getpixel((one,two))
		pixelArray[one][two] = str(r) + " " + str(g) + " " + str(b) + " " + str(a) + " "
file2 = open(output,"w")
for a in range(w):
	for b in range(h):
		file2.write(pixelArray[a][b])
file2.close()
subprocess.check_call(["editFile.exe", str(output), str(w), str(h)])
