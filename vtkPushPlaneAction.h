/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkPushPlaneAction.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPushPlaneAction - Controls plane-pushing action.
// .SECTION Description
// This class controls the "push" interaction for vtkImageActor slices,
// vtkVolumeMapper cropping planes, or clipping planes on all types of
// mappers.

#ifndef __vtkPushPlaneAction_h
#define __vtkPushPlaneAction_h

#include "vtkSurfaceCursorAction.h"

class vtkImageActor;
class vtkVolumeMapper;
class vtkAbstractMapper3D;
class vtkTransform;

class VTK_EXPORT vtkPushPlaneAction : public vtkSurfaceCursorAction
{
public:
  // Description:
  // Instantiate the object.
  static vtkPushPlaneAction *New();

  // Description:
  // Standard vtkObject methods
  vtkTypeRevisionMacro(vtkPushPlaneAction,vtkSurfaceCursorAction);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // These are the methods that are called when the action takes place.
  virtual void StartAction();
  virtual void StopAction();
  virtual void DoAction();

  // Description:
  // This method allows the action to constrain the cursor position.
  virtual void ConstrainCursor(double position[3], double normal[3]);

protected:
  vtkPushPlaneAction();
  ~vtkPushPlaneAction();

  vtkTransform *Transform;
  vtkImageActor *ImageActor;
  vtkVolumeMapper *VolumeMapper;
  vtkAbstractMapper3D *Mapper;
  int PlaneId;
  int PerpendicularPlane;
  double StartNormal[3];
  double StartOrigin[3];
  double Origin[3];
  double Normal[3];

  int IsPlaneValid() { return (this->PlaneId >= 0); }; 

  void GetPropInformation();
  void GetPlaneOriginAndNormal(double origin[3], double normal[3]);

  void SetStartOrigin(const double origin[3]) {
    this->StartOrigin[0] = origin[0];
    this->StartOrigin[1] = origin[1];
    this->StartOrigin[2] = origin[2]; };
     
  void GetStartOrigin(double origin[3]) {
    origin[0] = this->StartOrigin[0];
    origin[1] = this->StartOrigin[1];
    origin[2] = this->StartOrigin[2]; };

  void SetOrigin(const double origin[3]);

  void GetOrigin(double origin[3]) {
    origin[0] = this->Origin[0];
    origin[1] = this->Origin[1];
    origin[2] = this->Origin[2]; };

  void SetStartNormal(const double normal[3]) {
    this->StartNormal[0] = normal[0];
    this->StartNormal[1] = normal[1];
    this->StartNormal[2] = normal[2]; };
 
  void GetStartNormal(double normal[3]) {
    normal[0] = this->StartNormal[0];
    normal[1] = this->StartNormal[1];
    normal[2] = this->StartNormal[2]; };

  void SetNormal(const double normal[3]);

  void GetNormal(double normal[3]) {
    normal[0] = this->Normal[0];
    normal[1] = this->Normal[1];
    normal[2] = this->Normal[2]; };

private:
  vtkPushPlaneAction(const vtkPushPlaneAction&);  //Not implemented
  void operator=(const vtkPushPlaneAction&);  //Not implemented
};

#endif
