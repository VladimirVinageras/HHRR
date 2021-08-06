object FormVerTrabajadores: TFormVerTrabajadores
  Left = 4
  Top = 108
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Trabajadores de la Empresa'
  ClientHeight = 414
  ClientWidth = 792
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 1
    Top = 1
    Width = 789
    Height = 379
    TabOrder = 0
    object ListView1: TListView
      Left = 2
      Top = 3
      Width = 783
      Height = 374
      Columns = <
        item
          Caption = 'No. Identidad'
          Width = 80
        end
        item
          Caption = 'Nombre y Apellidos'
          Width = 140
        end
        item
          Caption = 'Direcci'#243'n Particular'
          Width = 200
        end
        item
          Caption = 'Tel'#233'fono'
          Width = 70
        end
        item
          Caption = 'Cargo'
          Width = 100
        end
        item
          Caption = 'Departamento'
          Width = 114
        end
        item
          Caption = 'Salario'
          Width = 75
        end>
      GridLines = True
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
  object Button1: TButton
    Left = 360
    Top = 385
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 1
    OnClick = Button1Click
  end
end
