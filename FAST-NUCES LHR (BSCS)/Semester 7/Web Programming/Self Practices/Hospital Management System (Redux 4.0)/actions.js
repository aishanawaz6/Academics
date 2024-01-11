//This file defines all the actions
import * as actions from './actionsTypes.js';

export const PATIENTAdded = name => (
    {
        type: actions.PATIENT_ADDED,
        payload: { name }
    }
)

export const PATIENTCheckup = id => (
    {
        type: actions.PATIENT_CHECKUP,
        payload: { id }
}) 

export const PATIENTRemoved = id => (
    {
        type: actions.PATIENT_REMOVED,
        payload: { id }
}) 
