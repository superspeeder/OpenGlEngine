#pragma once

#include <vector>
class IndexBuffer
{
private:
	unsigned int bufferRendererID;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
};

