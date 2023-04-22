#version 410 core

in vec3 normal;
in vec4 color;
out vec4 fragmentColor;

uniform float ambientStrength = 0.3f;
uniform vec4 ambientColor = vec4(1, 1, 1, 0);

uniform float lightStrength = 0.7;

struct DirectionalLight
{
    vec3 color;
    float ambientIntensity;
    vec3 direction;
    float diffuseIntensity;
};

uniform DirectionalLight directionalLight;

void main() {
    // Ambient
    vec4 ambient = ambientColor * ambientStrength;
    //vec4 ambient = vec4(directionalLight.color,1.0f) * directionalLight.ambientIntensity;

    // Diffuse
//    vec3 normalCorrected = normalize(normal);
//    vec3 lightDir = normalize(lightPos - FragPos);
//    float angleFactor = max(dot(normalCorrected, lightDir), 0.0);
//    vec4 diffuse = angleFactor * vec4(objectColor, 1.0f) * vec4(lightColor, 1.0f) * lightStrength;
    float diffuseFactor = max(dot(normalize(normal), normalize(directionalLight.direction)),0.0f);
    vec4 diffuse = vec4(directionalLight.color,1.0f) * directionalLight.diffuseIntensity * diffuseFactor;

   fragmentColor = (ambient + diffuse) * color /*+ specular*/;   //color given to current fragment (pixel)
}
