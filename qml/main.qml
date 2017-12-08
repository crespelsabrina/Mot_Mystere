import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.1
import QtQuick.Controls.Styles 1.2

import "script.js" as MyScript
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles.Desktop 1.0
import QtQuick.Dialogs.qml 1.0
import QtQuick.Extras 1.4
import QtQuick 2.7




ApplicationWindow {

    visible : true
    width: 384 // tel : 640
    height : 640 // tel 384
    minimumWidth: 500
    minimumHeight: 500
    color : "#00000000"

    id : root

    Image {
        id: fond
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "../Images/Grey-and-green-abstract-HD-pictures.jpg"

        Rectangle {
            id: row
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.topMargin: 50

            Rectangle {
                id: rectangle
                width: 250
                height: 50
                color: "#00000000"
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: titre
                    x: 0
                    y: 0
                    text: qsTr("Mystery Word")
                    anchors.horizontalCenterOffset: 2
                    anchors.leftMargin: 2
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                    anchors.top: parent.top
                    anchors.bottomMargin: 1
                    anchors.topMargin: -1
                    font.capitalization: Font.MixedCase
                    fontSizeMode: Text.HorizontalFit
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    textFormat: Text.AutoText
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 44
                    color : "#33ff33"
                    font.weight: Font.DemiBold
                    font.family: "Arial"
                }

            }

            Image {
                id: image6 //Point d'interrogation gauche
                width: 55
                height: 55
                anchors.rightMargin: 10
                anchors.right: rectangle.left
                anchors.verticalCenter: parent.verticalCenter
                source: "../Images/16124.png"
            }


            Image {
                id: image4 //Point d'interrogation droit
                width: 55
                height: 55
                anchors.leftMargin: 10
                anchors.left: rectangle.right
                fillMode: Image.PreserveAspectFit
                anchors.verticalCenter: parent.verticalCenter
                source: "../Images/16124.png"
            }
        }

        ComboBox {
            id: idDifficulty
            currentIndex: 2
            model : ["Facile", "Moyen", "Difficile", "Expert"]
            x: 35
            y: 249
            width: 109
            height: 21

            onCurrentIndexChanged:
            {
                myContext.mm.difficulty = currentIndex
                myContext.test("mm.difficulty");
            }
        }

        TextField {
            id: shuffleWord_champ
            x: 353
            width: 369
            height: 115
            anchors.top: parent.top
            anchors.topMargin: 101
            font.capitalization: Font.AllUppercase
            font.family: "Courier"
            readOnly: true
            font.pixelSize: 40
            anchors.verticalCenterOffset: -161
            anchors.horizontalCenterOffset: 1
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: qsTr("")
            textColor : "#1df409"

            Text{
                id: shuffleWord
                x: -4
                anchors.fill: parent
                color: "#1df409"
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                styleColor: "#000000"
                font.letterSpacing: 11
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.weight: Font.Bold
            }
        }

        TextField {
            id: wordProposed
            x: 316
            y: 368
            width: 369
            height: 115
            font.pixelSize: 32
            font.letterSpacing: 11
            anchors.horizontalCenterOffset: 1
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: qsTr("")
            font.capitalization: Font.AllUppercase
            opacity: 1
            clip: false
            validator: RegExpValidator { regExp: /[a-zA-Z]+/ }
            font.weight: Font.Bold
            maximumLength: shuffleWord.text.length
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }

        Image {
            id: imageSubmit
            x: 244
            width: 124
            height: 102
            anchors.top: parent.top
            anchors.topMargin: 238
            visible: false
            clip: false
            fillMode: Image.PreserveAspectCrop
            source: "../Images/Gartoon_actions_player_play.svg.png"

            Text {
                id: textSubmit
                x: 44
                y: 19
                width: 32
                height: 50
                color: "#070606"
                text: qsTr("Submit")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Courier"
                font.pixelSize: 5
                visible: true

                MouseArea{
                    anchors.rightMargin: -29
                    anchors.topMargin: -19
                    anchors.bottomMargin: -31
                    anchors.leftMargin: -19
                    anchors.fill : parent

                    onClicked:
                    {

                        state = myContext.check(wordProposed.text)
                        console.log(state);
                        progressBar.value = myContext.score

                        // wordProposed.text = ( state == "En Cours")? "" : state;
                        // = ( condition )? yes : no;
                        if (state == "In Progress")
                        {
                            wordProposed.text = "";
                        }
                        else
                        {
                            wordProposed.text = state;
                            imageSubmit.visible = false;
                            youWin.text.visible = true;
                        }
                    }
                }
            }
        }

        ProgressBar {
            id: progressBar
            x: 300
            width: 165
            height: 22
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: wordProposed.bottom
            anchors.topMargin: 12
            value: 7
            maximumValue: 7
            minimumValue: 0
            Text {
                id: textChances
                height: 22
                color: "#000000"
                text: qsTr("Chances")
                anchors.rightMargin: 0
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.top: parent.top
                font.underline: false
                font.italic: false
                font.family: "Arial"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 15
            }
            style: ProgressBarStyle{

                background: Rectangle {
                    radius: 20
                    color: "#0041474d"
                    border.width: 1
                    implicitWidth: 200
                    implicitHeight: 22
                }

                progress: Rectangle {
                    color: "#1df409"
                    radius: 20
                }
            }
        }

        /*Text {
            id: youWin
            x: 17
            y: 537
            color: "#27ea27"
            text: qsTr("You Win!!!")
            visible: false
            styleColor: "#df3c3c"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 75
        }*/
    }

    Image {
        id: image
        x: 40
        y: 295
        width: 120
        height: 50
        source: "../Images/Gartoon_actions_player_stop.svg.png"

        MouseArea{
            anchors.rightMargin: 3
            anchors.bottomMargin: 0
            anchors.leftMargin: -3
            anchors.topMargin: 0
            anchors.fill: parent
            onClicked:
            {
                shuffleWord.text = myContext.openDico();
                progressBar.value = 7;
                wordProposed.text = "";
                imageSubmit.visible = true;
            }
            Text {
                id: idPlay
                anchors.fill: parent
                width: 60
                height: 20
                color: "#0d0d0e"
                text: qsTr("Play")
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideMiddle
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 15
            }
        }
    }

    Row {
        x: 5
        y : 100
    }

    Text{
        id: textLettres
        x: 16
        y: 222
        width: 150
        height: 22
        text: qsTr("Niveau")
        textFormat: Text.AutoText
        horizontalAlignment: Text.AlignHCenter
        font.italic: true
        font.bold: true
        font.letterSpacing: 2
        font.pixelSize: 15
        color : "#33ff33"
    }

    TableView{
        id : idListView
        x: 5
        y : 541
        width: 336
        height : 89
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        model: myContext.wordList
        headerVisible : false
        backgroundVisible: false
        alternatingRowColors: false
        style: TableViewStyle{
            alternateBackgroundColor : "#9941474d"
            textColor : "#1df409"

        }

        TableViewColumn{
            role: "mot"
            title: "mot"
        }
    }
} //fin Window




