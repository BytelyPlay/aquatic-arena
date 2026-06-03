#version 460 core
out vec4 FragColor;

in vec3 texCoord;

uniform sampler2D tex;

void main() {
  FragColor = texture(tex, texCoord);
}