#version 410 core

in vec4 color;              //color received from the pipeline (and vertex shader)
in vec2 texCoord;
out vec4 fragmentColor;     //color sent to fragment on screen

// Adding uniform allows us to change these values per object in c++
// ambientColor might not need to be uniform because if we want to tint the screen, we normally
// would want to do it with all objects, not just a select few, right now it's here to show that
// we can do it
uniform float ambientStrength = 1.0f;
uniform vec4 ambientColor = vec4(1, 1, 1, 0);

uniform vec3 lightPos;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform sampler2D theTexture;

void main() {
   //              Farge   Lysfarge       Lysstyrke
   //fragmentColor = color;   //color given to current fragment (pixel)
   fragmentColor = texture(theTexture, texCoord);
}
