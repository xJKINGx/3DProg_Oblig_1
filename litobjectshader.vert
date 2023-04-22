#version 410 core

layout (location = 0) in vec4 positionIn;
layout (location = 1) in vec3 colorIn;

uniform mat4 pMatrix;                   // Leksjon 3
uniform mat4 vMatrix;                   // Leksjon 3
uniform mat4 matrix;

out vec3 color;

void main()
{
    gl_Position = pMatrix * vMatrix * matrix * positionIn;      //calculate the position of the model
    color = colorIn;
}
