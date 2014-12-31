#ifndef BOUNDINGBOX_H_
#define BOUNDINGBOX_H_

class BoundingBox : public BoundingShape{
public:
	BoundingBox(){}
	virtual ~BoundingBox(){}
	void generate(Vector3f* verts, unsigned int size){
		for(unsigned int i = 0; i < size; i++){
			if(verts[i].getX() < 0.0f && verts[i].getX() < sX){
				sX = verts[i].getX();
			}else if(verts[i].getX() > 0 && verts[i].getX() > lX){
				lX = verts[i].getX();
			}else{
				sX = 0.0f;
				lX = 0.0f;
			}

			if(verts[i].getY() < 0.0f && verts[i].getY() < sY){
				sY = verts[i].getY();
			}else if(verts[i].getY() > 0.0f && verts[i].getY() > lY){
				lY = verts[i].getY();
			}else{
				sY = 0.0f;
				lY = 0.0f;
			}

			if(verts[i].getZ() < 0.0f && verts[i].getZ() < sZ){
				sZ = verts[i].getZ();
			}else if(verts[i].getZ() > 0.0f && verts[i].getZ() > lZ){
				lZ = verts[i].getZ();
			}else{
				sZ = 0.0f;
				lZ = 0.0f;
			}
		}
	}
private:
	float sX = 0.0f, lX = 0.0f;
	float sY = 0.0f, lY = 0.0f;
	float sZ = 0.0f, lZ = 0.0f;
};


#endif /* BOUNDINGBOX_H_ */
