#version 410 core

layout(location = 0) in vec4 positionIn;   // 1st attribute buffer = vertex positions
//layout(location = 1) in vec4 colorIn;
layout(location = 1) in vec2 vertexUV;

out vec4 color;                           //color sent to rest of pipeline
out vec2 texCoord;

uniform mat4 pMatrix;                   // Leksjon 3
uniform mat4 vMatrix;                   // Leksjon 3
uniform mat4 matrix;                    //the matrix for the model


void main() {
  gl_Position = pMatrix * vMatrix * matrix * positionIn;      //calculate the position of the model
  texCoord = vertexUV;
  //color = colorIn;
}
