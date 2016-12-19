/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Tristan Magniez $
   $Notice: (C) Copyright 2016 by Megrov, Inc. All Rights Reserved. $
   ======================================================================== */

#if !defined(SDMETRICS_H)
#define SDMETRICS_H

//NOTE(doc): Length Conversion Macros

#define SDM_CM_TO_IN(x)     (0.3937F * (x))
#define SDM_IN_TO_CM(x)     (2.54F * (x))
#define SDM_IN_TO_M(x)      (0.0254F * (x))
#define SDM_IN_TO_MM(x)     (25.4F * (x))
#define SDM_KM_TO_MILE(x)   (0.6214F * (x))
#define SDM_M_TO_IN(x)      (39.37F * (x))
#define SDM_M_TO_YARD(x)    (1.093611F * (x))
#define SDM_MILE_TO_KM(x)   (1.609F * (x))
#define SDM_MM_TO_IN(x)     (0.03937F * (x))
#define SDM_YARD_TO_M(x)    (0.9144F * (x))
#define SDM_IN_TO_FT(x)     ((x) / 12.0)
#define SDM_IN_TO_YARD(x)   ((x) / 36.0)
#define SDM_IN_TO_MILE(x)   ((x) / 63360.0)
#define SDM_FT_TO_IN(x)     (12.0 * (x))
#define SDM_FT_TO_YARD(x)   ((x) / 3.0)
#define SDM_FT_TO_MILE(x)   ((x) / 5280.0)
#define SDM_MILE_TO_IN(x)   (63360.0 * (x))
#define SDM_MILE_TO_FT(x)   (5280.0 * (x))
#define SDM_MILE_TO_YARD(x) (1760.0 * (x))

//NOTE(doc): Weight Macros

#define SDM_G_TO_OZ(x)   (0.03527F * (x))
#define SDM_KG_TO_LBS(x) (2.2046F * (x))
#define SDM_LBS_TO_KG(x) (0.4545F * (x))
#define SDM_LBS_TO_OZ(x) (16.0F * (x))
#define SDM_OZ_TO_G(x)   (28.3527F * (x))
#define SDM_OZ_TO_LBS(x) ((x) / 16.0)

//NOTE(doc): Liquid Conversion Macros

#define SDM_CL_TO_OZ(x) (0.338F * (x))
#define SDM_ML_TO_OZ(x) (0.0338F * (x))
#define SDM_OZ_TO_CL(x) (2.95857988F * (x))
#define SDM_OZ_TO_ML(x) (29.5857F * (x))

/*
  NOTE(doc):
  In case you are unaware there are:
  16 ounces in a US quart
  20 ounces in a UK quart

  This, of course, makes gallons different
  too.  Supplied below are US to UK
  conversions as well.
*/

#define SDM_KL_TO_UKGAL(x)    (211.344F * (x))
#define SDM_KL_TO_USGAL(x)    (264.18F * (x))
#define SDM_L_TO_UKGAL(x)     (0.2199F * (x))
#define SDM_L_TO_UKQ(x)       (0.945F * (x))
#define SDM_L_TO_USGAL(x)     (0.26455F * (x))
#define SDM_L_TO_USQ(x)       (1.0582F * (x))
#define SDM_UKGAL_TO_KL(x)    (0.0047316F * (x))
#define SDM_UKGAL_TO_L(x)     (4.546F * (x))
#define SDM_UKGAL_TO_USGAL(x) (1.25F * (x))
#define SDM_UKQ_TO_L(x)       (1.0582F * (x))
#define SDM_UKQ_TO_USQ(x)     (1.25F * (x))
#define SDM_USGAL_TO_KL(x)    (0.003785F * (x))
#define SDM_USGAL_TO_L(x)     (3.78F * (x))
#define SDM_USGAL_TO_UKGAL(x) (0.8F * (x))
#define SDM_USQ_TO_L(x)       (0.945F * (x))
#define SDM_USQ_TO_UKQ(x)     (0.8F * (x))

//NOTE(doc): Area Conversion Macros

#define SDM_CM2_TO_IN2(x)   (0.155F * (x))
#define SDM_FT2_TO_M2(x)    (0.0930F * (x))
#define SDM_IN2_TO_CM2(x)   (6.4516F * (x))
#define SDM_IN2_TO_MM2(x)   (645.161F * (x))
#define SDM_KM2_TO_MILE2(x) (0.386F * (x))
#define SDM_M2_TO_FT2(x)    (10.75F * (x))
#define SDM_MILE2_TO_KM2(x) (2.5906F * (x))
#define SDM_MM2_TO_IN2(x)   (0.00155F * (x))

//NOTE(doc): Volume Conversion Macros

#define SDM_CM3_TO_IN3(x)   (0.061F * (x))
#define SDM_CM3_TO_IN3(x)   (0.061F * (x))
#define SDM_IN3_TO_CC(x)    (16.3934F * (x))
#define SDM_IN3_TO_CM3(x)   (16.3934F * (x))
#define SDM_KM3_TO_MILE3(x) (0.25F * (x))
#define SDM_M3_TO_YARD3(x)  (1.308F * (x))
#define SDM_MILE3_TO_KM3(x) (4.0F * (x))
#define SDM_YARD3_TO_M3(x)  (0.764526F * (x))

#endif
