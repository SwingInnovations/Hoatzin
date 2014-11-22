#include "OBJMesh.h"

OBJMesh::OBJMesh() {
	// TODO Auto-generated constructor stub

}

OBJMesh::OBJMesh(const std::string& fileName){
	std::ifstream in(fileName.c_str(), std::ios::in);
	if(!in){std::cout << "Error, could not open " << fileName << std::endl; }
	std::string line;

	while(std::getline(in, line)){
		if(line[0] == 'v' && line[1] == ' '){
			std::string vals = line.substr(2);
			float _x = 0.0f, _y = 0.0f, _z = 0.0f;

			std::string vX = vals.substr(0, vals.find(' '));
			_x = (float)atof(vX.c_str());

			std::string vY = vals.substr(vX.length()+1, vals.find('0'));
			_y = (float)atof(vY.c_str());

			std::string vZ = vals.substr(vals.find_last_of(' ')+1);
			_z = (float)atof(vZ.c_str());
			vertex.push_back(Vector3f(_x, _y, _z));
			std::cout << "Loaded Vertex: ";
			vertex.at(vertex.size()-1).print();
			std::cout << "\n";
		}
		if(line[0] == 'v' && line[1] == 't' && line[2] == ' '){
			std::string vals = line.substr(3);
			float _u = 0.0f, _v = 0.0f;

			std::string tU = vals.substr(0, vals.find(' '));
			_u = (float)atof(tU.c_str());

			std::string tV = vals.substr(tU.length()+1, vals.find(' '));
			_v = (float)atof(tV.c_str());
			texCoord.push_back(Vector2f(_u, _v));
			std::cout << "Loaded TexCoord: ";
			texCoord.at(texCoord.size()-1).print();
			std::cout << "\n";
		}
		//Extract a normal value
		if(line[0] == 'v' && line[1] == 'n' && line[2] == ' '){
			std::string vals = line.substr(3);
			float _x = 0.0f, _y = 0.0f, _z = 0.0f;

			std::string nX = vals.substr(0, vals.find(' '));
			_x = (float)atof(nX.c_str());

			std::string nY = vals.substr(nX.length()+1, vals.find(' '));
			_y = (float)atof(nY.c_str());

			std::string nZ = vals.substr(vals.find_last_of(' ')+1);
			_z =  (float)atof(nZ.c_str());
			normal.push_back(Vector3f(_x, _y, _z));
			std::cout << "Loaded normal: ";
			normal.at(normal.size()-1).print();
			std::cout << "\n";
		}
		//review this side;
		if(line[0]=='f' && line[1]==' '){
			std::string hLine = line.substr(2);
			int i = 0, j = 0, k = 0;
			//first element
			std::string face1 = hLine.substr(0, hLine.find(' '));
				std::string v1 = face1.substr(0, face1.find('/'));
				i = (int)atoi(v1.c_str());
				std::string t1 = face1.substr(face1.find('/')+1, face1.find_last_of('/'));
				j = (int)atoi(t1.c_str());
				std::string n1 = face1.substr(face1.find_last_of('/')+1);
				k = (int)atoi(n1.c_str());
				i--; j--; k--;
				indicies.push_back(i); indicies.push_back(j); indicies.push_back(k);
			std::string face2 = hLine.substr(hLine.find(' ')+1, hLine.find_last_of(' '));
				std::string v2 = face2.substr(0, face2.find('/'));
				i = (int)atoi(v2.c_str());
				std::string t2 = face2.substr(v2.length()+1, face2.find_last_of('/'));
				j = (int)atoi(t2.c_str());
				std::string n2 = face2.substr(face2.find_last_of('/')+1);
				k = (int)atoi(n2.c_str());
				i--; j--; k--;
				indicies.push_back(i); indicies.push_back(j); indicies.push_back(k);
			std::string face3 = hLine.substr(hLine.find_last_of(' ')+1);
				std::string v3 = face3.substr(0, face3.find('/'));
				i = (int)atoi(v3.c_str());
				std::string t3 = face3.substr(face3.find('/')+1, face3.find_last_of('/'));
				j = (int)atoi(t3.c_str());
				std::string n3 = face3.substr(face3.find_last_of('/')+1);
				k = (int)atoi(n3.c_str());
				i--; j--; k--;
				indicies.push_back(i); indicies.push_back(j); indicies.push_back(k);
		}

	}
	int inCount = 0;
	/*end parsing file*/
	for(unsigned int i = 0; i < indicies.size(); i+=3){
		verticies.push_back(Vertex(vertex.at(indicies.at(i)), texCoord.at(indicies.at(i+1)), normal.at(indicies.at(i+2))));
		inCount++;
		index.push_back(inCount);
	}
	std::cout << "Size of indicies: " << indicies.size() << std::endl;
}

OBJMesh::~OBJMesh() {
	// TODO Auto-generated destructor stub
}

