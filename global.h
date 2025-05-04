#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QStringList>

extern QString CURRENT_USER_ROLE;
extern QString CURRENT_USER_EMAIL;


bool isRoleAllowedForPage(const QString& role, const QString& page);

#endif // GLOBAL_H
