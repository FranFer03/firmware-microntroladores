/*******************************************************************************
* File Name: red.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_red_H) /* Pins red_H */
#define CY_PINS_red_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "red_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 red__PORT == 15 && ((red__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    red_Write(uint8 value);
void    red_SetDriveMode(uint8 mode);
uint8   red_ReadDataReg(void);
uint8   red_Read(void);
void    red_SetInterruptMode(uint16 position, uint16 mode);
uint8   red_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the red_SetDriveMode() function.
     *  @{
     */
        #define red_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define red_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define red_DM_RES_UP          PIN_DM_RES_UP
        #define red_DM_RES_DWN         PIN_DM_RES_DWN
        #define red_DM_OD_LO           PIN_DM_OD_LO
        #define red_DM_OD_HI           PIN_DM_OD_HI
        #define red_DM_STRONG          PIN_DM_STRONG
        #define red_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define red_MASK               red__MASK
#define red_SHIFT              red__SHIFT
#define red_WIDTH              1u

/* Interrupt constants */
#if defined(red__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in red_SetInterruptMode() function.
     *  @{
     */
        #define red_INTR_NONE      (uint16)(0x0000u)
        #define red_INTR_RISING    (uint16)(0x0001u)
        #define red_INTR_FALLING   (uint16)(0x0002u)
        #define red_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define red_INTR_MASK      (0x01u) 
#endif /* (red__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define red_PS                     (* (reg8 *) red__PS)
/* Data Register */
#define red_DR                     (* (reg8 *) red__DR)
/* Port Number */
#define red_PRT_NUM                (* (reg8 *) red__PRT) 
/* Connect to Analog Globals */                                                  
#define red_AG                     (* (reg8 *) red__AG)                       
/* Analog MUX bux enable */
#define red_AMUX                   (* (reg8 *) red__AMUX) 
/* Bidirectional Enable */                                                        
#define red_BIE                    (* (reg8 *) red__BIE)
/* Bit-mask for Aliased Register Access */
#define red_BIT_MASK               (* (reg8 *) red__BIT_MASK)
/* Bypass Enable */
#define red_BYP                    (* (reg8 *) red__BYP)
/* Port wide control signals */                                                   
#define red_CTL                    (* (reg8 *) red__CTL)
/* Drive Modes */
#define red_DM0                    (* (reg8 *) red__DM0) 
#define red_DM1                    (* (reg8 *) red__DM1)
#define red_DM2                    (* (reg8 *) red__DM2) 
/* Input Buffer Disable Override */
#define red_INP_DIS                (* (reg8 *) red__INP_DIS)
/* LCD Common or Segment Drive */
#define red_LCD_COM_SEG            (* (reg8 *) red__LCD_COM_SEG)
/* Enable Segment LCD */
#define red_LCD_EN                 (* (reg8 *) red__LCD_EN)
/* Slew Rate Control */
#define red_SLW                    (* (reg8 *) red__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define red_PRTDSI__CAPS_SEL       (* (reg8 *) red__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define red_PRTDSI__DBL_SYNC_IN    (* (reg8 *) red__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define red_PRTDSI__OE_SEL0        (* (reg8 *) red__PRTDSI__OE_SEL0) 
#define red_PRTDSI__OE_SEL1        (* (reg8 *) red__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define red_PRTDSI__OUT_SEL0       (* (reg8 *) red__PRTDSI__OUT_SEL0) 
#define red_PRTDSI__OUT_SEL1       (* (reg8 *) red__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define red_PRTDSI__SYNC_OUT       (* (reg8 *) red__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(red__SIO_CFG)
    #define red_SIO_HYST_EN        (* (reg8 *) red__SIO_HYST_EN)
    #define red_SIO_REG_HIFREQ     (* (reg8 *) red__SIO_REG_HIFREQ)
    #define red_SIO_CFG            (* (reg8 *) red__SIO_CFG)
    #define red_SIO_DIFF           (* (reg8 *) red__SIO_DIFF)
#endif /* (red__SIO_CFG) */

/* Interrupt Registers */
#if defined(red__INTSTAT)
    #define red_INTSTAT            (* (reg8 *) red__INTSTAT)
    #define red_SNAP               (* (reg8 *) red__SNAP)
    
	#define red_0_INTTYPE_REG 		(* (reg8 *) red__0__INTTYPE)
#endif /* (red__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_red_H */


/* [] END OF FILE */
