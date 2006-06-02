#ifndef __FILEOPTION_H__
#define __FILEOPTION_H__

#include "dialogoption.h"
class QString;

namespace gui {

/**
 FileOption - class for widget containing one editable string setting,
 while allowing to either type the name, or use dialog to pick the filename. User's choice<br>
 Used as one item type in option window<br>
*/

class FileOption : public DialogOption {
 Q_OBJECT
public:
 FileOption(const QString &_key=0,QWidget *parent=0,const QString &defValue=0);
 virtual void dialog(QString &value);
 virtual ~FileOption();
};

} // namespace gui

#endif
