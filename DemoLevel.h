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
#include "Utility/Math/Geom/Plane.h"
#include "Utility/Math/Geom/Box.h"

class DemoLevel : public GameState{
public:
	DemoLevel(int id){
		this->id = id;
	}

	void Init(){

		camPos = Vector3f(0.0, 0.0, -2.0);
		camera = new Camera(camPos, 66.0f, 1024.0f, 768.0f, 1.0f, 1000.0f);

		shader = new Shader("basicShader");
		tex = new Texture("grid.png");
		tex2 = new Texture("flower.jpg");
		Vector3f position(0.0, 0.0, -3.0);

		plane = new SWObject(new Mesh(new Plane(30, 30)), shader, tex2);
		plane->SetTranslateX(-20);
		plane->SetTranslateY(-20);
		plane->SetRotateX(90);
		box = new SWObject(new Mesh(new Box(position, 3, 3, 3)), shader, tex);

		rot = 0;
		rot2 = 0;
		rotAmt = 0;
		transX = 0; transZ = 0;
	}

	void UpdateAuto(AppWindow& app, int delta){
		rot2+= 0.025f * delta;
		box->SetRotateZ(rot2);
	}

	void UpdateInput(AppWindow& app, int delta){
		Input input = app.GetInput();
		if(input.isKeyDown(KEY::KEY_A)){
			transX += 0.025f*delta;
			camera->SetTranslateX(transX);
		}
		if(input.isKeyDown(KEY::KEY_D)){
			transX -= 0.025f*delta;
			camera->SetTranslateX(transX);
		}
		if(input.isKeyDown(KEY::KEY_W)){
			transZ += 0.025f*delta;
			camera->SetTranslateZ(transZ);
		}
		if(input.isKeyDown(KEY::KEY_S)){
			transZ -= 0.025f * delta;
			camera->SetTranslateZ(transZ);
		}
		camera->Update(input);
	}

	void Render(){
		//obj->Draw(*camera);
		box->Draw(*camera);
		plane->Draw(*camera);
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
	Camera* camera;
	Vector3f test;
	float rot;
	float rot2;
	float rotAmt;
	float transX, transZ;
	Vector3f camPos;
	SWObject *plane, *box;
};


#endif /* DEMOLEVEL_H_ */
