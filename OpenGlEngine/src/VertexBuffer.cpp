#include "VertexBuffer.h"
#include <GL/glew.h>


VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	glGenBuffers(size, &bufferRendererID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}


VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &bufferRendererID);
}

void VertexBuffer::Bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, bufferRendererID);
}

void VertexBuffer::Unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}