#include <file_ply_stl.h>
#include <iostream>

int main()
{
  _file_ply File_ply;

  vector<_vertex3f> Vertices;
  vector<_vertex3i> Triangles;

  if (File_ply.open("beethoven.ply")){
    File_ply.read(Vertices,Triangles);
    std::cout << "File read correctly" << std::endl;
  }
  else std::cout << "File can't be opened" << std::endl;
}
