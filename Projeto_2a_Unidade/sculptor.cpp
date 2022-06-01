#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
  nx = _nx;
  ny = _ny;
  nz = _nz;

  v = new Voxel **[nx];

  for (int i = 0; i < nx; i++) {
    v[i] = new Voxel *[ny];
  }
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      v[i][j] = new Voxel[nz];
    }
  }
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        v[i][j][k].isOn = false;
        v[i][j][k].r = 0;
        v[i][j][k].g = 0;
        v[i][j][k].b = 0;
        v[i][j][k].a = 0;
      }
    }
  }
}

Sculptor::~Sculptor() {}

void Sculptor::setColor(float r, float g, float b, float alpha) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
  v[x][y][z].isOn = true;
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
  v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z) { v[x][y][z].isOn = false; }

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {

  for (int i = x0; i < x1; i++) {
    for (int j = y0; j < y1; j++) {
      for (int k = z0; k < z1; k++) {
        v[i][j][k].isOn = true;
        v[i][j][k].r = r;
        v[i][j][k].g = g;
        v[i][j][k].b = b;
        v[i][j][k].a = a;
      }
    }
  }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
  for (int i = x0; i < x1; i++) {
    for (int j = y0; j < y1; j++) {
      for (int k = z0; k < z1; k++) {
        v[i][j][k].isOn = false;
      }
    }
  }
}

void Sculptor::putSphere(int x0, int y0, int z0, int raio) {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if ((pow(i - x0, 2) + pow(j - y0, 2) + pow(k - z0, 2)) <=
            pow(raio, 2)) {
          v[i][j][k].isOn = true;
          v[i][j][k].r = r;
          v[i][j][k].g = g;
          v[i][j][k].b = b;
          v[i][j][k].a = a;
        }
      }
    }
  }
}

void Sculptor::cutSphere(int x0, int y0, int z0, int raio) {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if ((pow(i - x0, 2) + pow(j - y0, 2) + pow(k - z0, 2)) <=
            pow(raio, 2)) {
          v[i][j][k].isOn = false;
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if ((pow(i - xcenter, 2) / pow(rx, 2)) +
                (pow(j - ycenter, 2) / pow(ry, 2)) +
                (pow(k - zcenter, 2) / (pow(rz, 2))) <=
            1) {
          v[i][j][k].isOn = true;
          v[i][j][k].r = r;
          v[i][j][k].g = g;
          v[i][j][k].b = b;
          v[i][j][k].a = a;
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if ((pow(i - xcenter, 2) / pow(rx, 2)) +
                (pow(j - ycenter, 2) / pow(ry, 2)) +
                (pow(k - zcenter, 2) / (pow(rz, 2))) <=
            1) {
          v[i][j][k].isOn = false;
        }
      }
    }
  }
}

void Sculptor::writeOFF(const char *filename) {
  int TotalVoxel = 0;
  int TotalFaces = 0;
  int TotalVertices = 0;

  std::ofstream fout;
  fout.open(filename);
  if (!fout.is_open()) {
    cout << "Erro ao iniciar o arquivo";
    exit(1);
  }

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].isOn) {
          TotalVoxel++;
        }
      }
    }
  }

  TotalFaces = TotalVoxel * 6;
  TotalVertices = TotalVoxel * 8;

  fout << "OFF" << endl
       << TotalVertices << " " << TotalFaces << " " << 0 << endl;

  for (int o = 0; o < nx; o++) {
    for (int p = 0; p < ny; p++) {
      for (int q = 0; q < nz; q++) {
        if (v[o][p][q].isOn) {
          fout << o - 0.5 << " " << p + 0.5 << " " << q - 0.5 << endl;
          fout << o - 0.5 << " " << p - 0.5 << " " << q - 0.5 << endl;
          fout << o + 0.5 << " " << p - 0.5 << " " << q - 0.5 << endl;
          fout << o + 0.5 << " " << p + 0.5 << " " << q - 0.5 << endl;
          fout << o - 0.5 << " " << p + 0.5 << " " << q + 0.5 << endl;
          fout << o - 0.5 << " " << p - 0.5 << " " << q + 0.5 << endl;
          fout << o + 0.5 << " " << p - 0.5 << " " << q + 0.5 << endl;
          fout << o + 0.5 << " " << p + 0.5 << " " << q + 0.5 << endl;
        }
      }
    }
  }

  int Nver = 0;

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].isOn) {
          fout << fixed;
          fout << 4 << setprecision(2) << ' ' << Nver + 0 << ' ' << Nver + 3 << ' ' << Nver + 2
               << ' ' << Nver + 1 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
               << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
          fout << 4 << setprecision(2) << ' ' << Nver + 4 << ' ' << Nver + 5 << ' ' << Nver + 6
               << ' ' << Nver + 7 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
               << ' ' << v[i][j][k].g << ' ' << v[i][j][k].a << endl;
          fout << 4 << setprecision(2) << ' ' << Nver + 0 << ' ' << Nver + 1 << ' ' << Nver + 5
               << ' ' << Nver + 4 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
               << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
          fout << 4 << setprecision(2) << ' ' << Nver + 0 << ' ' << Nver + 4 << ' ' << Nver + 7
               << ' ' << Nver + 3 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
               << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
          fout << 4 << setprecision(2) << ' ' << Nver + 3 << ' ' << Nver + 7 << ' ' << Nver + 6
               << ' ' << Nver + 2 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
               << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
          fout << 4 << setprecision(2) << ' ' << Nver + 1 << ' ' << Nver + 2 << ' ' << Nver + 6
               << ' ' << Nver + 5 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
               << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
          Nver = Nver + 8;
        }
      }
    }
  }

  //   for (int i = 0; i < nx; i++) {
  //   for (int j = 0; j < ny; j++) {
  //     for (int k = 0; k < nz; k++) {
  //       if (v[i][j][k].isOn) {
  //         fout << 4 << ' ' << Nver + 0 << ' ' << Nver + 3 << ' ' << Nver + 2
  //              << ' ' << Nver + 1 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
  //              << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
  //         fout << 4 << ' ' << Nver + 4 << ' ' << Nver + 5 << ' ' << Nver + 6
  //              << ' ' << Nver + 7 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
  //              << ' ' << v[i][j][k].g << ' ' << v[i][j][k].a << endl;
  //         fout << 4 << ' ' << Nver + 0 << ' ' << Nver + 1 << ' ' << Nver + 5
  //              << ' ' << Nver + 4 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
  //              << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
  //         fout << 4 << ' ' << Nver + 0 << ' ' << Nver + 4 << ' ' << Nver + 7
  //              << ' ' << Nver + 3 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
  //              << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
  //         fout << 4 << ' ' << Nver + 3 << ' ' << Nver + 7 << ' ' << Nver + 6
  //              << ' ' << Nver + 2 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
  //              << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
  //         fout << 4 << ' ' << Nver + 1 << ' ' << Nver + 2 << ' ' << Nver + 6
  //              << ' ' << Nver + 5 << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g
  //              << ' ' << v[i][j][k].b << ' ' << v[i][j][k].a << endl;
  //         Nver = Nver + 8;
  //       }
  //     }
  //   }
  // }

  cout << "Voxel " << TotalVoxel << endl;
  cout << "Total Faces " << TotalFaces << endl;
  cout << "Total Vertices " << TotalVertices << endl;

  fout.close();
  cout << "Arquivo gerado com sucesso";
}