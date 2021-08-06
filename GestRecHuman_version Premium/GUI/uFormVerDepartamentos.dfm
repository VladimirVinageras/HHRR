object FormVerDepartamentos: TFormVerDepartamentos
  Left = 133
  Top = 173
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsSingle
  Caption = 'Departamentos de la Empresa'
  ClientHeight = 334
  ClientWidth = 553
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
    Left = 3
    Top = 2
    Width = 546
    Height = 296
    TabOrder = 0
    object ListView1: TListView
      Left = 6
      Top = 6
      Width = 534
      Height = 283
      Columns = <
        item
          Caption = 'C'#243'digo'
          Width = 70
        end
        item
          Caption = 'Nombre'
          Width = 100
        end
        item
          Caption = 'Jefe de Departamento'
          Width = 120
        end
        item
          Caption = 'Cantidad de Cargos'
          Width = 105
        end
        item
          Caption = 'Cantidad de Trabajadores'
          Width = 135
        end>
      GridLines = True
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
  object Button1: TButton
    Left = 240
    Top = 304
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 1
    OnClick = Button1Click
  end
end
