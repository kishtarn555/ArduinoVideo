# ArduinoVideo
A small project where I try to generate composite video from an arduino Mega

I started this project without knowing neither arduino or how video signal works... So it may have hundreds of flaws.

What I have achieved is a 80x64 black and white (no gray) resolution.
with this I got, still image, scrolling text (3 screens) and 2 frame animation.

Currently working on how to make it work with interrupts instead of a loop with counted-ish cycles.

My code is really messy as I never intended to be seen by anyone.

# ExternalLinks

Image that helped me use fast IO: https://lynx2015.files.wordpress.com/2015/08/arduino-mega-pinout-diagram.png 

Future project, color with VGA (dont want to try with composite) :http://tinyvga.com/vga-timing

The blog that helped a lot: http://people.ece.cornell.edu/land/courses/ece5760/video/gvworks/GV's%20works%20%20NTSC%20demystified%20-%20B&W%20Video%20and%20Sync%20-%20Part%201.htm
