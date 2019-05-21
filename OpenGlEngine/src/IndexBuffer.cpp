#include "IndexBuffer.h"
#include <GL/glew.h>


IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int size)
{
	glGenBuffers(size, &bufferRendererID);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}


IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &bufferRendererID);
}

void IndexBuffer::Bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferRendererID);
}

void IndexBuffer::Unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}