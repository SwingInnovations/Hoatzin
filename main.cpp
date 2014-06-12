
#include "AppWindow.h"

int main(int argc, char** argv){
	AppWindow app("Test", 1024, 768);
	app.SetOpenGLVersion(3, 3);
	app.Start();
	return 0;
}
