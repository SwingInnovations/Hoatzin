#ifndef MESH_H_
#define MESH_H_

#include <GL/glew.h>
#include <vector>
#include "Vertex.h"

class Vertex2D_UV;

class Mesh{
public:
	Mesh();
	Mesh(Vertex2D_UV* vertices, unsigned int numVerts){
		mDrawCount = numVerts;

		glGenVertexArrays(1, &m_VertexArrayObject);
		glBindVertexArray(m_VertexArrayObject);

		std::vector<Vector3f> position;
		std::vector<Vector2f> texCoords;

		position.reserve(numVerts);
		texCoords.reserve(numVerts);

		for(unsigned int i = 0; i < numVerts; i++){
			position.push_back(*vertices[i].GetVertices());
			texCoords.push_back(*vertices[i].GetTexCoord());
		}

		glGenBuffers(NUM_BUFFERS, mVertexBuffer);

		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[POSITION_VB]);
		glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(position[0]), &position[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[TEXCOORD_VB]);
		glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindVertexArray(0);
	}

	void Draw(){
		glBindVertexArray(m_VertexArrayObject);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
	}

	~Mesh(){
		glDeleteVertexArrays(1, &m_VertexArrayObject);
	}

private:
	enum{
		POSITION_VB,
		TEXCOORD_VB,
		NUM_BUFFERS
	};
	GLuint m_VertexArrayObject;
	GLuint mVertexBuffer[NUM_BUFFERS];
	unsigned int mDrawCount;
};

class Mesh2{
public:
	Mesh2(){

	}
	Mesh2(Vertex2D* vertices, unsigned int numVerts){
		mDrawCount = numVerts;

		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);

		glGenBuffers(1, &mVBO[POSITION_VB]);
		glBindBuffer(GL_ARRAY_BUFFER, mVBO[POSITION_VB]);
		glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(Vector3f), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindVertexArray(0);
	}

	~Mesh2(){
		glDeleteVertexArrays(1, &mVAO);
	}

	void Draw(){
		glBindVertexArray(mVAO);

		glEnableVertexAttribArray(0);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
	}
private:
	enum{
		POSITION_VB,
		NUM_BUFFERS
	};
	GLuint mVAO;
	GLuint mVBO[NUM_BUFFERS];
	unsigned int mDrawCount;
};



#endif /* MESH_H_ */
