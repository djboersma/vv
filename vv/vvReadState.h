#ifndef VVREADSTATE_H
#define VVREADSTATE_H

#include <string>
#include <memory>

class vvMainWindow;
class QXmlStreamReader;
class QFile;

class vvReadState
{
public:
  vvReadState();
  virtual ~vvReadState();
  
  virtual void Run(vvMainWindow* vvWindow, const std::string& file);
    
protected:
  
  void ReadGUI();
  void ReadTree();
  std::string  ReadImage();
  std::string  ReadFusion(int index);
  std::string  ReadOverlay(int index);
  std::string  ReadVector(int index);

  std::auto_ptr<QXmlStreamReader> m_XmlReader;
  std::auto_ptr<QFile> m_File;
  vvMainWindow* m_Window;
  int m_TreeItemCount;
};

#endif // VVREADSTATE_H
