#ifndef MESH_H_
#define MESH_H_

#include <GL/glew.h>
#include <vector>
#include "Vertex.h"

class Vertex;
class Vertex2D_UV;


class Mesh{

public:
	Mesh(){

	}

	Mesh(Vertex* vertices,unsigned int numVerts, int* index, unsigned int numInd){
		mNumVert = numVerts;
		mDrawCount = numInd;

		std::cout << sizeof(vertices[0]);

		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);

		std::vector<Vector3f> vertex;
		std::vector<Vector2f> texCoord;
		std::vector<Vector3f> normal;

		vertex.reserve(mNumVert);
		texCoord.reserve(mNumVert);
		normal.reserve(mNumVert);

		for(unsigned int i = 0; i < mNumVert; i++){
			vertex.push_back(*vertices[i].GetVertices());
			texCoord.push_back(*vertices[i].GetTexCoord());
			normal.push_back(*vertices[i].GetVertices());
		}

		glGenBuffers(NUM_BUFFERS, mVBO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[VERTEX_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert * sizeof(vertex[0]), &vertex[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[TEXCOORD_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert * sizeof(texCoord[0]), &texCoord[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[NORMAL_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert * sizeof(normal[0]), &normal[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVBO[INDEX_BUFFER]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mDrawCount * sizeof(index[0]), &index[0], GL_STATIC_DRAW);

		glBindVertexArray(0);
		std::cout << "Generated Mesh" << std::endl;
	}

	void Draw(){
		glBindVertexArray(mVAO);

		glDrawElements(GL_TRIANGLES, mDrawCount, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		std::cout << "Draw count" << mDrawCount << std::endl;
		std::cout << "numVerts:" << mNumVert << std::endl;
	}

	~Mesh(){
		std::cout << "Draw count" << mDrawCount << std::endl;
		std::cout << "numVerts" << mNumVert;
		glDeleteVertexArrays(1, &mVAO);
	}
private:
	enum{
		VERTEX_BUFFER,
		TEXCOORD_BUFFER,
		NORMAL_BUFFER,
		INDEX_BUFFER,
		NUM_BUFFERS
	};
	GLuint mVAO;
	GLuint mVBO[NUM_BUFFERS];
	unsigned int mDrawCount;
	unsigned int mNumVert;
};

//class Mesh{
//public:
//	Mesh();
//	Mesh(Vertex2D_UV* vertices, unsigned int numVerts){
//		mDrawCount = numVerts;
//
//		glGenVertexArrays(1, &m_VertexArrayObject);
//		glBindVertexArray(m_VertexArrayObject);
//
//		std::vector<Vector3f> position;
//		std::vector<Vector2f> texCoords;
//
//		position.reserve(numVerts);
//		texCoords.reserve(numVerts);
//
//		for(unsigned int i = 0; i < numVerts; i++){
//			position.push_back(*vertices[i].GetVertices());
//			texCoords.push_back(*vertices[i].GetTexCoord());
//		}
//
//		glGenBuffers(NUM_BUFFERS, mVertexBuffer);
//
//		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[POSITION_VB]);
//		glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(position[0]), &position[0], GL_STATIC_DRAW);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer[TEXCOORD_VB]);
//		glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
//		glEnableVertexAttribArray(1);
//		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
//
//		glBindVertexArray(0);
//	}
//
//	void Draw(){
//		glBindVertexArray(m_VertexArrayObject);
//
//		glEnableVertexAttribArray(0);
//		glEnableVertexAttribArray(1);
//
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glBindVertexArray(0);
//	}
//
//	~Mesh(){
//		glDeleteVertexArrays(1, &m_VertexArrayObject);
//	}
//
//private:
//	enum{
//		POSITION_VB,
//		TEXCOORD_VB,
//		NUM_BUFFERS
//	};
//	GLuint m_VertexArrayObject;
//	GLuint mVertexBuffer[NUM_BUFFERS];
//	unsigned int mDrawCount;
//};

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
