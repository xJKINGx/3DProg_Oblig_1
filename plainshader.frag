#version 410 core

in vec3 normal;
in vec3 color;
out vec4 fragmentColor;
in vec3 fragPos;

uniform vec3 lightPos;

struct DirectionalLight
{
    vec3 color;
    float ambientIntensity;
    vec3 direction;
    float diffuseIntensity;
};

uniform DirectionalLight directionalLight;

uniform vec3 viewPos; // The position of the camera
uniform float specularStrength = 0.5f;

void main() {
    // Ambient
    vec3 ambient = directionalLight.color * directionalLight.ambientIntensity;

    // Diffuse
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(fragPos - lightPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * directionalLight.color * directionalLight.diffuseIntensity;

    // Specular
    vec3 viewDir = normalize(fragPos - viewPos);
    vec3 reflectDir = reflect(-lightDir, normal);

    // The last parameter here is important. The higher the power we raise this to...
    // ... the smaller the effect of the specular light.
    // The "light orb" generated by the specular light will be smaller, but brighter.
    // The smaller the power raised, the bigger, but also dimmer, this "light orb" will be.
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * directionalLight.color;

    vec3 phong = (ambient + diffuse + specular) * color;

    fragmentColor = vec4(phong, 1.0f);   //color given to current fragment (pixel)
}
