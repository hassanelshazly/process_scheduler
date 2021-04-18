import QtQuick 2.12

Rectangle {
    id: root

    width: 480
    height: 240

    property var model
    signal addSignal()
    signal removeSignal(start_time: int)

    gradient: Gradient {
        GradientStop { position: 0.0; color: "#dbddde" }
        GradientStop { position: 1.0; color: "#5fc9f8" }
    }

    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 20

        height: 48

        color: "#53d769"
        border.color: Qt.lighter(color, 1.1)

        Text {
            anchors.centerIn: parent

            text: "Add job!"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                root.addSignal()
            }
        }
    }

    ListView {
        anchors.fill: parent
        anchors.margins: 16
        anchors.bottomMargin: 64

        clip: true

        orientation: ListView.Horizontal

        spacing: 8

        model: root.model

        delegate: jobDelegate
    }

    Component {
        id: jobDelegate

        Rectangle {
            id: wrapper

            width: duration * 5
            height: 32

            gradient: Gradient {
                GradientStop { position: 0.0; color: "#f8306a" }
                GradientStop { position: 1.0; color: "#fb5b40" }
            }

            Text {
                anchors.centerIn: parent

                font.pixelSize: 10

                text: label
            }

            MouseArea {
                anchors.fill: parent
            }

            ListView.onRemove: SequentialAnimation {
                PropertyAction { target: wrapper; property: "ListView.delayRemove"; value: true }
                NumberAnimation { target: wrapper; property: "scale"; to: 0; duration: 250; easing.type: Easing.InOutQuad }
                PropertyAction { target: wrapper; property: "ListView.delayRemove"; value: false }
            }

            ListView.onAdd: SequentialAnimation {
                NumberAnimation { target: wrapper; property: "scale"; from: 0; to: 1; duration: 250; easing.type: Easing.InOutQuad }
            }
        }
    }
}
