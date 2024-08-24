import { useState } from "react"

export interface Props{
    name:string,
    age:number,
    isMarried:boolean
}


 const Person = (props:Props) => {
    const [isShowInfo,setShowInfo] = useState<boolean>(false)

    const toggleInfo = () => {
        setShowInfo(!isShowInfo)
    }

  return (
    
    <div>
        {isShowInfo && (
        <>
            <p>Name = {props.name} Age = {props.age} This Person {props.isMarried? "is Married" :"is enjoying singlehood"} </p>
        </>
        )}
        <button onClick={toggleInfo}> Display Info </button>
    </div>
  )
}

export  default Person



interface User {
  name: string;
  email: string;
  phone: string;
}

const users = [
  {
    name: "John Doe",
    email: "John_Doe@mail.com",
    phone: "0712345678",
  }
]

ZOD
z.string()
z.email()
z.date()

export function UserComponent({name, email, phone}: User) {

  return (
    <div>
      
        <div>
          <ul>
            {users.map((user) => (
            <div key={user.name}>
              <li>Username: {user.name}</li>
              <li>Email: {user.email}</li>
              <li>Contact: {user.phone}</li>
            </div>
             ))}
          </ul>
        </div>

        <div>{name}</div>
        <div>{email}</div>
        <div>{phone}</div>
     
    </div>
  )
}