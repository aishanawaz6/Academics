import {createSlice, PayloadAction} from '@reduxjs/toolkit'
import { act } from '@testing-library/react';

export interface Volunteers{
    Name:string;
    area:string;
}

interface VolunteersState{
    volunteers:Volunteers[]
}

const initialStateVolunteers:VolunteersState={
    volunteers:[],
};
const khidmatVolunteerSlice=createSlice({
    name:'volunteerHistory',
    initialState:initialStateVolunteers,
    reducers:{
        updateVolunteers:(state,action:PayloadAction<Volunteers[]>)=>{
            state.volunteers=action.payload;
        },
        removeVolunteer: (state, action: PayloadAction<{ Name: string }>) => {
            state.volunteers = state.volunteers.filter(volunteer => volunteer.Name !== action.payload.Name);
            console.log('After removal:', state.volunteers);
         },
        
    },
    });

export const {updateVolunteers,removeVolunteer}=khidmatVolunteerSlice.actions;
export default khidmatVolunteerSlice.reducer;
