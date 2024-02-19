import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import zoo 1.0

Window {
    visible: true
    width: 600
    height: 500
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    title: qsTr("Zoo")

    Zoo {
        id: canvas
        anchors.fill: parent
    }
}
