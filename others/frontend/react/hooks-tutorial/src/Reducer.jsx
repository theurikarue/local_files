import { useReducer ,React} from 'react'




const UserForm = () => {
    const [state,dispatch] = useReducer(
        (state,action)=>(
        {
            ...state,
            ...action
        }),
    {
        first:"",
        last:""
    })
  return (
    <div>
        <input 
            type="text" 
            value={state.first}
            onChange={(e)=>dispatch({first:e.target.value})}/>
        <input 
            type="text" 
            value={state.last}
            onChange={(e)=>dispatch({last:e.target.value})} />
    
    <div>First:{state.first}</div>
    <div>Last:{state.last}</div>
    </div>
  )
}

const NameList = () => {
    const [state,dispatch] = useReducer(
        (state,action)=>{
            switch (action.type){
                case "SET_NAME":
                    return {...state,name:action.payload}
                case "ADD_NAME":
                    return {...state,
                        names:[...state.names,state.name],
                        name:"",
                    }
                default:
                        return state;
            }
        },
        {
            names:[],
            name:"",
        }
    
    ) 
  return (
    <div>
        <div>
            {state.names.map((name,index)=>(<div>{name}</div>))}
        </div>
        <input type="text" 
        value={state.name} 
        onChange={(e)=>
            dispatch({type:"SET_NAME",payload:e.target.value})}
        />
        <button onClick={()=>dispatch({type:"ADD_NAME"})}>
            Add Name
        </button>
    </div>
  )
}

const Reducer = () => {
  return (
    <div>
        <NameList/>
        <UserForm/>
    </div>
  )
}

export default Reducer