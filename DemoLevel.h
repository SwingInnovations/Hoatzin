#ifndef DEMOLEVEL_H_
#define DEMOLEVEL_H_

#include "Utility/GameState.h"
#include "Utility/Mesh.h"
#include "Utility/Math/Vector.h"
#include "Utility/Vertex.h"
#include "Graphics/Texture.h"
#include "Graphics/Shader.h"

class DemoLevel : public GameState{
public:
	DemoLevel(int id){
		this->id = id;
	}

	void Init(){
		Vertex2D verts[3] = {
				Vertex2D(Vector3f(0.0, 0.5, 0.0)),
				Vertex2D(Vector3f(-0.5, -0.5, 0.0)),
				Vertex2D(Vector3f(0.5, -0.5, 0.0))
		};

		Vertex2D_UV verts2[3] = {
				Vertex2D_UV(Vector3f(0.0, 0.5, 0.0), Vector2f(0.0, 0.0)),
				Vertex2D_UV(Vector3f(0.5, -0.5, 0.0), Vector2f(1.0, 1.0)),
				Vertex2D_UV(Vector3f(-0.5, -0.5, 0.0), Vector2f(0.0, 1.0))
		};

		mMesh = new Mesh(verts2, (sizeof(verts2)/sizeof(verts2[0])));
		mesh = new Mesh2(verts, (sizeof(verts) / sizeof(verts[0])));
		shader = new Shader("basicShader");
		tex = new Texture("grid.png");
	}

	void Update(AppWindow& app, int delta){

	}

	void Render(){
		shader->Bind();
		tex->bind(0);
		mMesh->Draw();
	}

	int GetID(){
		return id;
	}
private:
	int id;
	Mesh2* mesh;
	Mesh *mMesh;
	Shader* shader;
	Texture* tex;
};


#endif /* DEMOLEVEL_H_ */
