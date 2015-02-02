#ifndef MESH_H_
#define MESH_H_

#include <GL/glew.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Vertex.h"
#include "OBJMesh.h"
#include "Math/Geom/Shape.h"
#include "Math/Geom/Plane.h"
#include "Math/Geom/Box.h"

class Vertex;
class Vertex2D_UV;

namespace MESH_TYPE{
	enum{
		MODEL_OBJ
	};
};

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
			vertex.push_back(*vertices[i].getVerticies());
			texCoord.push_back(*vertices[i].getTexCoord());
			normal.push_back(*vertices[i].getVerticies());
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

	Mesh(Shape* shape){
		mNumVert = shape->getVerticiesSize();
		mDrawCount = shape->getIndiciesSize();
		std::vector<Vector3f> vertex;
		std::vector<Vector2f> texCoord;
		std::vector<Vector3f> normal;

		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);

		vertex.reserve(mNumVert);
		texCoord.reserve(mNumVert);
		normal.reserve(mNumVert);
		for(unsigned int i = 0; i < mNumVert; i++){
			vertex.push_back(*shape->getVerticies()->getVerticies());
			texCoord.push_back(*shape->getVerticies()->getTexCoord());
			normal.push_back(*shape->getVerticies()->getNormal());
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
		glBufferData(GL_ARRAY_BUFFER, mNumVert*sizeof(normal[0]), &normal[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVBO[INDEX_BUFFER]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mDrawCount * sizeof(shape->getIndicies()[0]), &shape->getIndicies()[0], GL_STATIC_DRAW);

		glBindVertexArray(0);
	}

	Mesh(Plane* shape){
		mNumVert = 4;
		mDrawCount = shape->getIndiciesSize();

		std::vector<Vector3f> vertex;
		std::vector<Vector2f> texCoord;
		std::vector<Vector3f> normal;

		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);

		vertex.reserve(mNumVert);
		texCoord.reserve(mNumVert);
		normal.reserve(mNumVert);
		for(unsigned int i = 0; i < mNumVert; i++){
			vertex.push_back(*shape->mVertices[i].getVerticies());
			texCoord.push_back(*shape->mVertices[i].getTexCoord());
			normal.push_back(*shape->mVertices[i].getNormal());
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
		glBufferData(GL_ARRAY_BUFFER, mNumVert*sizeof(normal[0]), &normal[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVBO[INDEX_BUFFER]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mDrawCount * sizeof(shape->GetIndicies()[0]), &shape->GetIndicies()[0], GL_STATIC_DRAW);

		glBindVertexArray(0);
	}

	Mesh(Box* box){
		mNumVert = 8;
		mDrawCount = box->getIndiciesSize();

		std::vector<Vector3f> vertex;
		std::vector<Vector2f> texCoord;
		std::vector<Vector3f> normal;

		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);

		vertex.reserve(mNumVert);
		texCoord.reserve(mNumVert);
		normal.reserve(mNumVert);
		for(unsigned int i = 0; i < mNumVert; i++){
			vertex.push_back(*box->mVertices[i].getVerticies());
			texCoord.push_back(*box->mVertices[i].getTexCoord());
			normal.push_back(*box->mVertices[i].getNormal());
		}

		glGenBuffers(NUM_BUFFERS, mVBO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[VERTEX_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert* sizeof(vertex[0]), &vertex[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[TEXCOORD_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert* sizeof(texCoord[0]), &texCoord[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[NORMAL_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert*sizeof(normal[0]), &normal[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVBO[INDEX_BUFFER]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mDrawCount*sizeof(box->getIndicies()[0]), &box->getIndicies()[0], GL_STATIC_DRAW);

		glBindVertexArray(0);
	}

	Mesh(const std::string& file, int type){
		std::vector<Vector3f> vertex;
		std::vector<Vector2f> texCoord;
		std::vector<Vector3f> normal;
		std::vector<Vector3f> tangent;
		std::vector<Vector3f> biTangent;
		std::vector<int> index;

		switch(type){
		case 0://loading an obj
			OBJMesh* tMesh;
			tMesh = new OBJMesh(file);
			//something something
			mNumVert = tMesh->getVerticiesSize();
			mDrawCount = tMesh->getIndiciesSize();
			vertex.reserve(mNumVert);
			texCoord.reserve(mNumVert);
			normal.reserve(mNumVert);
			for(int i = 0; i < tMesh->getVerticiesSize(); i++){
				vertex.push_back(*tMesh->verticies[i].getVerticies());
				texCoord.push_back(*tMesh->verticies[i].getTexCoord());
				normal.push_back(*tMesh->verticies[i].getNormal());
			}
			tangent = genTangent(vertex, texCoord);
			biTangent = genBiTangent(vertex, texCoord);
			index = tMesh->index;
			delete tMesh;
			tMesh = 0;
			break;
		default:
			tMesh = 0;
			break;
		}

		glGenVertexArrays(1, &mVAO);
		glBindVertexArray(mVAO);

		glGenBuffers(NUM_BUFFERS, mVBO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[VERTEX_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert*sizeof(vertex[0]), &vertex[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[TEXCOORD_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert*sizeof(texCoord[0]), &texCoord[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[NORMAL_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert*sizeof(normal[0]), &normal[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[TANGENT_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert*sizeof(tangent[0]), &tangent[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO[BITANGENT_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, mNumVert*sizeof(biTangent[0]), &biTangent[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVBO[INDEX_BUFFER]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mDrawCount*sizeof(index[0]), &index[0], GL_STATIC_DRAW);
	}


	void draw(){
		glBindVertexArray(mVAO);

		glDrawElements(GL_TRIANGLES, mDrawCount, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	}

	~Mesh(){
		std::cout << "Draw count" << mDrawCount << std::endl;
		std::cout << "numVerts" << mNumVert;
		glDeleteVertexArrays(1, &mVAO);
	}
private:
	std::vector<Vector3f>genTangent(std::vector<Vector3f>& vert, std::vector<Vector2f>& tex){
		std::vector<Vector3f> ret;
		for(unsigned int i = 0; i < vert.size(); i+=3){
			Vector3f v0 = vert[i+0];
			Vector3f v1 = vert[i+1];
			Vector3f v2 = vert[i+2];

			Vector2f uv0 = tex[i+0];
			Vector2f uv1 = tex[i+1];
			Vector2f uv2 = tex[i+2];

			Vector3f dP1 = v1 - v0;
			Vector3f dP2 = v2 - v0;

			Vector2f dUV1 = uv1 - uv0;
			Vector2f dUV2 = uv2 - uv0;

			float r = 1.0f / (dUV1.getX() * dUV2.getY() - dUV1.getY() * dUV2.getX());
			Vector3f a = (dP1 * dUV2.getY())*r;
			Vector3f b = (dP2 * dUV1.getY())*r;
			Vector3f tangent = a - b;
			ret.push_back(tangent);
			ret.push_back(tangent);
			ret.push_back(tangent);
		}
		return ret;
	}

	std::vector<Vector3f>genBiTangent(std::vector<Vector3f>& vert, std::vector<Vector2f>& tex){
		std::vector<Vector3f> ret;
		for(unsigned int i = 0; i < vert.size(); i+=3){
			Vector3f v0 = vert[i+0];
			Vector3f v1 = vert[i+1];
			Vector3f v2 = vert[i+2];

			Vector2f uv0 = tex[i+0];
			Vector2f uv1 = tex[i+1];
			Vector2f uv2 = tex[i+2];

			Vector3f dP1 = v1 - v0;
			Vector3f dP2 = v2 - v0;

			Vector2f dUV1 = uv1 - uv0;
			Vector2f dUV2 = uv2 - uv0;

			float r = 1.0f / (dUV1.getX() * dUV2.getY() - dUV1.getY() * dUV2.getX());
			Vector3f a = (dP1 * dUV2.getX())*r;
			Vector3f b = (dP2 * dUV1.getX())*r;
			Vector3f biTangent = b - a;
			ret.push_back(biTangent);
			ret.push_back(biTangent);
			ret.push_back(biTangent);
		}
		return ret;
	}
	enum{
		VERTEX_BUFFER,
		TEXCOORD_BUFFER,
		NORMAL_BUFFER,
		INDEX_BUFFER,
		TANGENT_BUFFER,
		BITANGENT_BUFFER,
		NUM_BUFFERS
	};
	GLuint mVAO;
	GLuint mVBO[NUM_BUFFERS];
	unsigned int mDrawCount;
	unsigned int mNumVert;
};


#endif /* MESH_H_ */
