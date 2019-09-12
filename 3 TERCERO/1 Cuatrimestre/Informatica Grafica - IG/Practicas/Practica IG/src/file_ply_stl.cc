//******************************************************************************
// class to read ply files of triangles
//
// Domingo Martín Perandres (c) 2017
//
// Gnu Public Licence
//******************************************************************************

#include "file_ply_stl.h"

using namespace std;

//******************************************************************************
//
//******************************************************************************

int _file_ply::open(const string &File_name)
{
  File.open(File_name.c_str(),ios::in);

  if (File.good()) return 1;
  else {
    cout << "Error: the file " << File_name << " cannot be opened" << endl;
    return 0;
  }
}

//******************************************************************************
//
//******************************************************************************

void _file_ply::get_token(istringstream &Line_stream1,string &Token1)
{
//  cout <<  "buscando en:" << Line_stream1.str() << endl;
  getline(Line_stream1,Token1,' ');
//  cout <<  "salida:" << Token1 << endl;
}

//******************************************************************************
//
//******************************************************************************

bool _file_ply::get_new_line(ifstream &File,istringstream &Line_stream)
{
  string Line;
  if (getline(File,Line)){
//    cout << "leido:" << Line << endl;
    Line_stream.str(Line);
    Line_stream.seekg(0);
    return true;
  }
  else return false;
}


//******************************************************************************
//
//******************************************************************************

void _file_ply::read(vector<_vertex3f> &Vertices,vector<_vertex3i> &Triangles)
{
  string Token;
  istringstream Line_stream;

  setlocale(LC_ALL, "C");

  get_new_line(File,Line_stream);
  get_token(Line_stream,Token);
  if(Token=="ply"){
    get_new_line(File,Line_stream);
    get_token(Line_stream,Token);
    if(Token=="format"){
      get_token(Line_stream,Token);
      if(Token=="ascii"){
        do{
          get_new_line(File,Line_stream);
          get_token(Line_stream,Token);
        } while (Token!="element");
        get_token(Line_stream,Token);
        if(Token=="vertex"){
          get_token(Line_stream,Token);
          Vertices.resize(stoi(Token));
          do{
            get_new_line(File,Line_stream);
            get_token(Line_stream,Token);
          } while (Token!="element");
          get_token(Line_stream,Token);
          if(Token=="face"){
            get_token(Line_stream,Token);
            Triangles.resize(stoi(Token));
            do{
              get_new_line(File,Line_stream);
              get_token(Line_stream,Token);
            } while (Token!="end_header");
            for (unsigned int i=0;i<Vertices.size();i++){
              get_new_line(File,Line_stream);
              //

              get_token(Line_stream,Token);
              Vertices[i].x=stof(Token);
              get_token(Line_stream,Token);
              Vertices[i].y=stof(Token);
              get_token(Line_stream,Token);
              Vertices[i].z=stof(Token);

//              cout << " leido " << Vertices[i].x << " " << Vertices[i].y << " " << Vertices[i].z << endl;
            }
            for (unsigned int i=0;i<Triangles.size();i++){
              get_new_line(File,Line_stream);
              //
              get_token(Line_stream,Token);
              if (stoi(Token)==3){
                get_token(Line_stream,Token);
                Triangles[i]._0=stoi(Token);
                get_token(Line_stream,Token);
                Triangles[i]._1=stoi(Token);
                get_token(Line_stream,Token);
                Triangles[i]._2=stoi(Token);
              }
            }
          }
          else{
            cerr << "Error: no face element found" << endl;
          }
        }
        else{
          cerr << "Error: no vertex element found" << endl;
        }
      }
      else{
        cerr << "Error: only ascii format is allowed" << endl;
      }
    }
    else{
      cerr << "Error: no format found" << endl;
    }
  }
  else{
    cerr << "Error: the file is not a PLY file" << endl;
  }
}

//******************************************************************************
//
//******************************************************************************

void _file_ply::close()
{
  File.close();
}

