#ifndef BOUNDINGSHAPE_H_
#define BOUNDINGSHAPE_H_


class BoundingShape{
public:
	virtual bool isIntersected(BoundingShape other){return false;};
	virtual ~BoundingShape();
};


#endif /* BOUNDINGSHAPE_H_ */
