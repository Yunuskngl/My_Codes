from PIL import Image, ImageDraw, ImageFont
import textwrap



pic = Image.open('abc.png')
draw = ImageDraw.Draw(pic)

font1 = ImageFont.truetype("Gidole-Regular.ttf",40)  
color = "White"

text = "askdmakmd"
wrapped_text = textwrap.fill(text,width=20)

pos = [(10,10),(10,160),(10,310),(10,460)]

for i, pos in enumerate(pos):
    draw.text(pos,wrapped_text,fill = color,font= font1)
    
pic.save('out.png')
