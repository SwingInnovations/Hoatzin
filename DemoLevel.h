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
#include "Graphics/Camera.h"

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

		Vertex2D_UV vert3[3] = {
				Vertex2D_UV(Vector3f(0.0, -0.55, 0.0), Vector2f(0.5, 1.0)),
				Vertex2D_UV(Vector3f(0.3, -0.8, 0.0), Vector2f(1.0, 0.0)),
				Vertex2D_UV(Vector3f(-0.3, -0.8, 0.0), Vector2f(0.0, 0.0)),
		};

		camPos = Vector3f(0.0, 0.0, -2.0);
		camera = new Camera(camPos, 66.0f, 1024.0f, 768.0f, 1.0f, 1000.0f);

		mMesh = new Mesh(verts2, (sizeof(verts2)/sizeof(verts2[0])));
		fMesh = new Mesh(vert3, sizeof(vert3)/sizeof(vert3[0]));
		mesh = new Mesh2(verts, (sizeof(verts) / sizeof(verts[0])));
		shader = new Shader("basicShader");
		tex = new Texture("grid.png");
		tex2 = new Texture("flower.jpg");
		transform = new Transform();
		rot = 0;
		rot2 = 0;
		rotAmt = 0;
	}

	void UpdateAuto(AppWindow& app, int delta){
		rot2+= 0.025f * delta;
//		rotAmt-= 0.000022 * delta;
//		transform->SetRotateZ(rot2);
		transform->SetRotateZ(rot2*3.0);
		transform->SetTranslateZ(-3.0);
		std::cout << "Delta: " << delta << std::endl;
	}

	void UpdateInput(AppWindow& app, int delta){

	}

	void Render(){
		shader->Update(*transform, *camera);
		shader->Bind();
		tex->bind(0);
		mMesh->Draw();

		tex2->bind(0);
		fMesh->Draw();

	}

	int GetID(){
		return id;
	}
private:
	int id;
	Mesh2* mesh;
	Mesh *mMesh;
	Mesh *fMesh;
	Shader* shader;
	Texture* tex;
	Texture* tex2;
	Transform* transform;
	Camera* camera;
	Vector3f test;
	float rot;
	float rot2;
	float rotAmt;
	Vector3f camPos;
};


#endif /* DEMOLEVEL_H_ */
