#include "VertexArray.h"

VertexArray::VertexArray(std::vector<BufferStructure> structures) :
	m_structures(structures)
{
	glCreateVertexArrays(1, &m_id);
	for (BufferStructure st : structures)
	{
		for (Attribute attrib : st.GetAttributes())
		{
			if (attrib.IsFloat)
				glVertexArrayAttribFormat(m_id, attrib.Index, attrib.Length, GL_FLOAT, false, attrib.Offset);
			else
				glVertexArrayAttribIFormat(m_id, attrib.Index, attrib.Length, GL_INT, attrib.Offset);
			glEnableVertexArrayAttrib(m_id, attrib.Index);
			if (attrib.InstanceDivisor != 0)
				glVertexArrayBindingDivisor(m_id, attrib.Index, attrib.InstanceDivisor);
		}
	}
}

void VertexArray::SetIndexBuffer(Buffer<int> buffer)
{
	glVertexArrayElementBuffer(m_id, buffer.GetID());
	m_hasIndex = true;
}

void VertexArray::Destroy()
{
	glDeleteBuffers(1, &m_id);
}

void VertexArray::SetBuffer(int structure, TBuffer buffer, int offset)
{
	if (!m_hasIndex)
		m_length = buffer.GetSize() / buffer.GetTSize();
	for (Attribute attrib : m_structures[structure].GetAttributes())
	{
		GLsizei len = m_structures[structure].GetTotalSize();
		glVertexArrayVertexBuffer(m_id, attrib.Index, buffer.GetID(), offset, len);
	}
}