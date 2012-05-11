/*
 * main.cpp
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */
#include <iostream>
#include "Assets/AssetManager.h"
#include "Exceptions/InvalidArgumentException.h"
#include "Exceptions/ResourceNotFoundException.h"
#include "Display/SurfaceLoader.h"

using namespace std;

int main(int argc, char* argv[]){
  cout<<"Loading assets from: "<<argv[1]<<endl;

  AssetManager manager(new SurfaceLoader());
  try {
    manager.loadAssets(argv[1]);
  } catch (ResourceNotFoundException e){
    cout<<e.what()<<endl;
  } catch (InvalidArgumentException e){
    cout<<e.what()<<endl;
  }
}
