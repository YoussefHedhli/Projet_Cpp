#include "global.h"
#include <QMap>

QString CURRENT_USER_ROLE = "";
QString CURRENT_USER_EMAIL = "";

bool isRoleAllowedForPage(const QString& role, const QString& page) {
    // All roles can access "gs_employe"
    if (page == "gs_employe")
        return true;

    QMap<QString, QStringList> roleAccess = {
        {"Responsable équipe", {"gs_equipe"}},
        {"Coordinateur match", {"gs_match"}},
        {"Responsable RH", {}}, // No specific access for now
        {"Responsable billets", {"gs_billet"}},
        {"Responsable sponsors", {"gs_sponsor"}}
    };

    if (!roleAccess.contains(role))
        return false;

    return roleAccess[role].contains(page);
}
