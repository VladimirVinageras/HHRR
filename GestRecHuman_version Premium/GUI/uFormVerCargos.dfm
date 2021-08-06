object FormVerCargos: TFormVerCargos
  Left = 153
  Top = 138
  Width = 488
  Height = 411
  BorderIcons = [biSystemMenu]
  Caption = 'Cargos de la Empresa'
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
    Top = 3
    Width = 477
    Height = 347
    TabOrder = 0
  end
  object ListView1: TListView
    Left = 5
    Top = 8
    Width = 469
    Height = 337
    Columns = <
      item
        Caption = 'Nombre'
        Width = 118
      end
      item
        Caption = 'Plazas Aprobadas'
        Width = 142
      end
      item
        Caption = 'Plazas Reales'
        Width = 125
      end
      item
        Caption = 'Salario'
        Width = 80
      end>
    GridLines = True
    TabOrder = 1
    ViewStyle = vsReport
  end
  object Button1: TButton
    Left = 205
    Top = 354
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 2
    OnClick = Button1Click
  end
end
