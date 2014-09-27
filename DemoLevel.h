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
#include "Utility/SWObject.h"
#include "Graphics/Camera.h"

class DemoLevel : public GameState{
public:
	DemoLevel(int id){
		this->id = id;
	}

	void Init(){

		Vertex verts[] = {Vertex(Vector3f(-0.75, 0.25, 0.0), Vector2f(0.0, 0.0)),
							Vertex(Vector3f(-0.75, -0.25, 0.0), Vector2f(0.0, 1.0)),
							Vertex(Vector3f(0.75, -0.25, 0.0), Vector2f(1.0, 1.0)),
							Vertex(Vector3f(0.75, 0.25, 0.0), Vector2f(1.0, 0.0))};
		int indicies[] = {0, 1, 2, 3, 2, 0};

		camPos = Vector3f(0.0, 0.0, -2.0);
		camera = new Camera(camPos, 66.0f, 1024.0f, 768.0f, 1.0f, 1000.0f);

		shader = new Shader("basicShader");
		tex = new Texture("grid.png");
		tex2 = new Texture("flower.jpg");

		obj = new SWObject(new Mesh(verts, sizeof(verts)/sizeof(verts[0]), indicies, sizeof(indicies)/sizeof(indicies[0])), shader, tex);

		transform = new Transform();
		rot = 0;
		rot2 = 0;
		rotAmt = 0;
	}

	void UpdateAuto(AppWindow& app, int delta){
		rot2+= 0.025f * delta;
		obj->SetTranslateZ(-3.0);
	}

	void UpdateInput(AppWindow& app, int delta){
		Input input = app.GetInput();
		camera->Update(input);
	}

	void Render(){
		obj->Draw(*camera);
	}

	int GetID(){
		return id;
	}

	~DemoLevel(){
		std::cout << SDL_GetError() << std::endl;
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
	SWObject *obj;
};


#endif /* DEMOLEVEL_H_ */
