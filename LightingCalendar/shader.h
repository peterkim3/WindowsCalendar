#pragma once

const char *vertexShaderSource =
    "#version 330 core\n"
    "layout(location = 0) in vec3 aPos;\n"
    "layout(location = 1) in vec3 aNormal;\n"
    "layout(location = 2) in vec2 aTexCoords;\n"
    "out vec3 FragPos;\n"
    "out vec3 Normal;\n"
    "out vec2 TexCoords;\n"
    "void main()\n"
    "{\n"
    "   FragPos = aPos;\n"
    "   Normal = aNormal;\n"
    "   TexCoords = vec2(aTexCoords.x, aTexCoords.y);\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "}\0";

const char *fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 FragPos;\n"
    "in vec3 Normal;\n"
    "in vec2 TexCoords;\n"
    "uniform vec3 viewPos;\n"
    "uniform sampler2D texture1;\n"
    "void main()\n"
    "{\n"
    "   vec3 viewDir = normalize(viewPos - FragPos);\n"
    "   float ambientStrength = max(dot(Normal, viewDir), 0);\n"
    "   if (ambientStrength > 0.5) {\n"
    "   FragColor = texture(texture1, TexCoords) * pow(ambientStrength,10);\n"
    "   } else {\n"
    "   FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
    "   }\n"
    //"   FragColor = texture(texture1, TexCoords);\n"
    //"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";