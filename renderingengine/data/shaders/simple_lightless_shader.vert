#version 460 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 texCoord;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProjection;

out vec3 outTexCoord;

void main {
  gl_Position = uProjection * uView * uModel * vec4(vertex, 1.0);
  outTexCoord = texCoord;
}