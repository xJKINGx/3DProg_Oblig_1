    #version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 FragPos;
out vec3 Normal;

uniform mat4 model; // model matrix aka. mMatrix
uniform mat4 camMatrix;

void main()
{
    FragPos = vec3(model * vec4(aPos, 1.0));

    // This is not optimal, we should calculate this on the CPU and then send it over to the GPU.
    // This is only a proof of concept, to show what is actually happening to the normalvectors.
    Normal = mat3(transpose(inverse(model))) * aNormal;

    gl_Position = camMatrix * model * vec4(aPos, 1.0f);
}
