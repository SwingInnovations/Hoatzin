#ifndef DEMOLEVEL_H_
#define DEMOLEVEL_H_

#include <cmath>

#include "Utility/GameState.h"
#include "Utility/Mesh.h"
#include "Utility/Transform.h"
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
				Vertex2D_UV(Vector3f(0.0, 0.5, 0.0), Vector2f(0.5, 1.0)),
				Vertex2D_UV(Vector3f(0.5, -0.5, 0.0), Vector2f(1.0, 0.0)),
				Vertex2D_UV(Vector3f(-0.5, -0.5, 0.0), Vector2f(0.0, 0.0))
		};

		test = Vector3f(0.5, 2.5, 9.8);

		mMesh = new Mesh(verts2, (sizeof(verts2)/sizeof(verts2[0])));
		mesh = new Mesh2(verts, (sizeof(verts) / sizeof(verts[0])));
		shader = new Shader("basicShader");
		tex = new Texture("grid.png");
		transform = new Transform();

	}

	void Update(AppWindow& app, int delta){
		float posdif = 0.0;
		posdif++;
		transform->SetTranslateX(cos(posdif));
		std::cout << "Updating" << std::endl;

		std::cout << "Test Vector" << std::endl;
		test.Print();

	}

	void Render(){
		shader->Bind();
		shader->Update(*transform);
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
	Transform* transform;
	Vector3f test;
};


#endif /* DEMOLEVEL_H_ */
