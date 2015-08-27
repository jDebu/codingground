#include <iostream>

#include <stdio.h>
#include <math.h>
#include "global.h"

using namespace std;

class Vertex{
    public:
    void setCoordX(int x){coordX=x;}
    void setCoordY(int y){coordY=y;}
    void setCoords(int x,int y){coordX=x;coordY=y;}
    int getCoordX(){return coordX;}
    int getCoordY(){return coordY;}
    protected: int coordX;int coordY;
};

class Triangle:public Vertex{
    public:
    void setVertexs(Vertex v1,Vertex v2,Vertex v3){V1=v1;V2=v2;V3=v3;}
    void setPoint(Vertex p){P=p;}
    bool isTriangle(){return true;}
    int Orientation(Vertex v1,Vertex v2,Vertex v3){
    //return (a1x-a3x)*(a2y-a3y) - (a1y-a3y)*(a2x-a3x);
    return (v1.getCoordX()-v3.getCoordX())*(v2.getCoordY()-v3.getCoordY()) - (v1.getCoordY()-v3.getCoordY())*(v2.getCoordX()-v3.getCoordX());
    }
    int inTriangle(){
        if(Orientation(V1,V2,V3)>=0){
            return Orientation(V1,V2,P)>0 && Orientation(V2,V3,P)>0 && Orientation(V3,V1,P)>0;}
        else 
            {return Orientation(V1,V2,P)<0 && Orientation(V2,V3,P)<0 && Orientation(V3,V1,P)<0;}
        
    }
   /* int pointInTriangles(FixedArray &myArray){
        int cont=0;
        for(int i=0;i<6006,i=i+6){
            Vertex v1,v2,v3;
            //set Coordinate of Vertex
            v1.setCoords(myArray[i],myArray[i+1]);
            v2.setCoords(myArray[i+2],myArray[i+3]);
            v3.setCoords(myArray[i+4],myArray[i+5]);
            setVertexs(v1,v2,v3);//ok
            if(inTriangle()){
                cont++;
            }
        }
        return cont;
    }*/
    protected: Vertex V1,V2,V3,P;
};


int main(void){
    Vertex point;
    Triangle t;
    point.setCoords(900,900);
    t.setPoint(point);//ok
    int cont=0;
    Vertex v1,v2,v3;
    for(int i=0;i<6006;i=i+6){
        //set Coordinate of Vertex
        v1.setCoords(g_triangles[i],g_triangles[i+1]);
        v2.setCoords(g_triangles[i+2],g_triangles[i+3]);
        v3.setCoords(g_triangles[i+4],g_triangles[i+5]);
        t.setVertexs(v1,v2,v3);//ok
        if(t.inTriangle()){
            cont++;
        }
    }
    printf("El punto(23,45) esta contenido en %d triangulos\n",cont);
      
   // printf("%d", t.pointInTriangles(g_triangles));
    return 0;
}





