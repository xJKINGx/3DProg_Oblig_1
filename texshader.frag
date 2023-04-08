#version 410 core

in vec2 texCoord;
out vec4 fragmentColor;     //color sent to fragment on screen

in vec4 color;

uniform sampler2D theTexture;

void main() {
   //              Farge   Lysfarge       Lysstyrke

   fragmentColor = texture(theTexture,texCoord);
   //fragmentColor = color;   //color given to current fragment (pixel)
}
