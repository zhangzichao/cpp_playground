#include <pangolin/pangolin.h>
#include <thread>
#include <unistd.h>

void createWindow(bool* quit)
{
  pangolin::CreateWindowAndBind("Main",640,480);

  pangolin::OpenGlRenderState s_cam(
      pangolin::ProjectionMatrix(640,480,420,420,320,240,0.2,100),
      pangolin::ModelViewLookAt(-2,2,-2, 0,0,0, pangolin::AxisY)
  );

  // Create Interactive View in window
  pangolin::Handler3D handler(s_cam);
  pangolin::View& d_cam = pangolin::CreateDisplay()
          .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f/480.0f)
          .SetHandler(&handler);

  while( !pangolin::ShouldQuit() )
  {
      // Clear screen and activate view to render into
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      d_cam.Activate(s_cam);

      // Render OpenGL Teapot
      pangolin::glDrawColouredCube();

      // Swap frames and Process Events
      pangolin::FinishFrame();
  }
  *quit = true;
}

class WindowCreator
{
public:
  WindowCreator()
    :win_thread_(createWindow, &quit_)
  {
  }

  ~WindowCreator()
  {
    // alternatvie for one window
//    win_thread_.join();

    // check flag before quit
    win_thread_.detach();
    while(!quit_)
    {  }
  }

private:
  std::thread win_thread_;
  bool quit_ = false;
};


int main(int argc, char *argv[])
{
//  bool win_quit = false;
//  std::thread win1(createWindow, &win_quit);
  WindowCreator win;

  std::cout << "sleep for 5 seconds\n";
  sleep(5);
  std::cout << "awake";

//  win1.detach();
//  while(!win_quit)
//  {}

  return 0;
}
