/*=========================================================================
  Program:   vv                     http://www.creatis.insa-lyon.fr/rio/vv

  Authors belong to:
  - University of LYON              http://www.universite-lyon.fr/
  - Léon Bérard cancer center       http://oncora1.lyon.fnclcc.fr
  - CREATIS CNRS laboratory         http://www.creatis.insa-lyon.fr

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the copyright notices for more information.

  It is distributed under dual licence

  - BSD        See included LICENSE.txt file
  - CeCILL-B   http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
======================================================================-====*/
#ifndef VVTOOLRIGIDREG_H
#define VVTOOLRIGIDREG_H
#include <QtDesigner/QDesignerExportWidget>
#include <QDialog>

#include "vvToolBase.h"
#include "vvToolWidgetBase.h"
#include "vvMainWindowBase.h"
#include "vvMainWindow.h"
#include "ui_vvToolRigidReg.h"
#include "vtkMatrix4x4.h"

//------------------------------------------------------------------------------
class vvToolRigidReg:
    public vvToolWidgetBase,
    public vvToolBase<vvToolRigidReg>,
    private Ui::vvToolRigidReg
{
  Q_OBJECT
public:
  vvToolRigidReg(vvMainWindowBase * parent=0, Qt::WindowFlags f=0);
  ~vvToolRigidReg();
  virtual void InputIsSelected(std::vector<vvSlicerManager *> & m);
public slots:
  virtual void apply();
  virtual bool close();
  virtual void reject();
  //-----------------------------------------------------
  static void Initialize() {
    SetToolName("Register");
    SetToolMenuName("Register");
    SetToolIconFilename(":/common/icons/register.png");
    SetToolTip("Register Image.");
    SetToolExperimental(true);
  }
  void SetXvalue();
  void SetYvalue();
  void SetZvalue();
  void SetOrderXtrans();
  void SetOrderYtrans();
  void SetOrderZtrans();
  void SetOrderXrot();
  void SetOrderYrot();
  void SetOrderZrot();
  void UpdateXtranslider();
  void UpdateXtransb();
  void UpdateYtranslider();
  void UpdateYtransb();
  void UpdateZtranslider();
  void UpdateZtransb();
  void UpdateXrotslider();
  void UpdateXrotsb();
  void UpdateYrotslider();
  void UpdateYrotsb(); 
  void UpdateZrotslider();
  void UpdateZrotsb();  
  void SetOverlay();
  void SaveFile();
  void ReadFile();
  void ResetTransform();
  void SetRotationCenter();
  void SetSliderRanges();
  void UpdateTextEditor(vtkMatrix4x4 *matrix,QString SetOrder);
  void InitializeSliders();
  
  protected:
  Ui::vvToolRigidReg ui;
  vvSlicerManager * mInput1;
  vvSlicerManager * mInput2;
  vvMainWindow * mWindow;
  QString mOrder;
  bool mTwoInputs;
  std::vector<int> mImageSize;
  void SetTransform(double tX, double tY, double tZ, double aX, double aY, double aZ);
  void SetTransform(vtkMatrix4x4 * matrix);
}; // end class vvToolRigidReg
//------------------------------------------------------------------------------

#endif
