import * as actions from './actionsTypes.js'
let lastId = 0;

export default function reducer(state = [], action){
    switch (action.type){
        case actions.PATIENT_ADDED:
            return [
                ...state,
                {
                    id: ++lastId,
                    name: action.payload.name,
                    checkup: false,
                    message:''
                }
            ];
        case actions.PATIENT_REMOVED:
            return state.filter(patient => patient.id !== action.payload.id);
        case actions.PATIENT_CHECKUP:
            return state.map(patient => {
                if (patient.id === action.payload.id) {
                    return {
                        ...patient,
                        message: patient.checkup ? 'Patient Checked' : 'Patient Not Checked'
                    };
                } else {
                    return patient;
                }
            });
        default:    
            return state;
    }   
}