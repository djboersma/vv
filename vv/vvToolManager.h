/*=========================================================================

  Program:   vv
  Module:    $RCSfile: vvToolManager.h,v $
  Language:  C++
  Date:      $Date: 2010/02/24 11:42:42 $
  Version:   $Revision: 1.3 $
  Author :   David Sarrut (david.sarrut@creatis.insa-lyon.fr)

  Copyright (C) 2008
  Léon Bérard cancer center http://oncora1.lyon.fnclcc.fr
  CREATIS-LRMN http://www.creatis.insa-lyon.fr

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, version 3 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  =========================================================================*/

#ifndef VVTOOLMANAGER_H
#define VVTOOLMANAGER_H

#include "clitkCommon.h"

class vvToolCreatorBase;
class vvMainWindowBase;

//------------------------------------------------------------------------------
// Manage a list of ToolCreator. Each tool will be automagically
// inserted into a list at construction time, before main. Then the
// MainWindow will call the 'Initialize' to insert the tool in the
// menu bar.
class vvToolManager {

public:

  /// Get or build unique instance with this method
  static vvToolManager * GetInstance();  

  /// Add a tool creator in the list (called before main, via static member initialization)
  static void AddTool(vvToolCreatorBase * v);

  /// Called in MainWindow, insert all tools into the menu
  static void InsertToolsInMenu(vvMainWindowBase * m);
  
protected:

  /// Singleton object pointer
  static vvToolManager * mSingleton;

  /// list of all tool creators
  std::vector<vvToolCreatorBase *> mListOfTools;
};
//------------------------------------------------------------------------------

#endif

