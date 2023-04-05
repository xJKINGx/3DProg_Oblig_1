#version 410 core

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform float ambientStrength = 0.1f;
uniform float lightStrength = 0.7;
uniform vec3 lightColor = vec3(0.8, 0.8, 0.3);
uniform vec3 objectColor = vec3(0.7, 0.7, 0.7);

uniform vec3 lightPos;
uniform vec3 cameraPos;

uniform float specularStrength = 0.5;
uniform float specularExponent = 64;


void main()
{
    // ambient light - aka. background light, usually very low
    vec3 ambient = ambientStrength * lightColor;

    // diffuse light - allows us to use light to shine upon objects and make them brighter
    vec3 normalCorrected = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float angleFactor = max(dot(normalCorrected, lightDir), 0.0);
    vec3 diffuse = angleFactor * objectColor * lightColor * lightStrength;

    // Specular light - makes objects more shiny, shows reflectiveness/smoothness
    vec3 viewDirection = normalize(cameraPos - FragPos);
    float spec = 0.0;
    if (angleFactor > 0.0)
    {
        vec3 reflectDirection = reflect(-lightDir, normalCorrected);
        // the pow here changes the size of the "light orb" that appears on surfaces, higher value = smaller orb
        // this can also more easily simulate how reflective a surface is, the more reflective it is, the smaller the orb
        spec = pow(max(dot(viewDirection, reflectDirection), 0.0), specularExponent);
    }
    vec3 specular = spec * lightColor * specularStrength;

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0); // set all 4 vector values to 1.0
}
